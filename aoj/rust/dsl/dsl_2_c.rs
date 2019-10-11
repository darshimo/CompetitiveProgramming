pub fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

pub fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read::<String>()
        .split_whitespace()
        .map(|e| e.parse().ok().unwrap())
        .collect()
}

pub fn read_vec2<T: std::str::FromStr>(n: u32) -> Vec<Vec<T>> {
    (0..n).map(|_| read_vec()).collect()
}

pub fn read_col<T: std::str::FromStr>(n: u32) -> Vec<T> {
    (0..n).map(|_| read()).collect()
}

enum KDTree {
    Empty,
    Node(usize, Box<KDTree>, Box<KDTree>),
}

use KDTree::{Empty, Node};

//ベクタを丸ごと交換するよう修正する必要がある
fn partition(v: &mut Vec<Vec<i32>>, p: usize, r: usize, d: usize) -> usize {
    let x = v[r - 1][d];
    let mut i = p;
    for j in p..(r - 1) {
        if v[j][d] <= x {
            let tmp = v[i].clone();
            v[i] = v[j].clone();
            v[j] = tmp;
            i += 1;
        }
    }
    let tmp = v[i].clone();
    v[i] = v[r - 1].clone();
    v[r - 1] = tmp;
    i
}

fn quicksort(v: &mut Vec<Vec<i32>>, p: usize, r: usize, d: usize) {
    if p + 1 < r {
        let q = partition(v, p, r, d);
        quicksort(v, p, q, d);
        quicksort(v, q + 1, r, d);
    }
}

fn make_kdtree(v: &mut Vec<Vec<i32>>, p: usize, r: usize, d: usize, k: usize) -> KDTree {
    if p + 1 > r {
        return Empty;
    }

    quicksort(v, p, r, d);

    let mid = (p + r) / 2;

    Node(
        mid,
        Box::new(make_kdtree(v, p, mid, (d + 1) % k, k)),
        Box::new(make_kdtree(v, mid + 1, r, (d + 1) % k, k)),
    )
}

fn find_kdtree(
    t: &KDTree,
    v: &Vec<Vec<i32>>,
    sp: &Vec<i32>,
    tp: &Vec<i32>,
    d: usize,
    k: usize,
    ps: &mut Vec<i32>,
) {
    match t {
        Empty => {}
        Node(i, l, r) => {
            let p = &v[*i];
            let mut i: usize = 0;
            while i < k {
                if p[i] < sp[i] || tp[i] < p[i] {
                    break;
                }
                i += 1;
            }
            if i == k {
                ps.push(p[k]);
            }

            if sp[d] < p[d] {
                find_kdtree(l, &v, sp, tp, (d + 1) % k, k, ps);
            }
            if p[d] < tp[d] {
                find_kdtree(r, &v, sp, tp, (d + 1) % k, k, ps);
            }
        }
    }
}

fn main() {
    let n: u32 = read::read();
    let mut points: Vec<Vec<i32>> = read::read_vec2(n);
    for i in 0..n {
        points[i as usize].push(i as i32);
    }
    let q: u32 = read::read();
    let ranges: Vec<Vec<i32>> = read::read_vec2(q);

    let t = make_kdtree(&mut points, 0, n as usize, 0, 2);

    for i in 0..(q as usize) {
        let mut ps: Vec<i32> = Vec::new();
        let sp: Vec<i32> = vec![ranges[i][0], ranges[i][2]];
        let tp: Vec<i32> = vec![ranges[i][1], ranges[i][3]];
        find_kdtree(&t, &points, &sp, &tp, 0, 2, &mut ps);
        ps.sort();
        for p in &ps {
            println!("{}", p);
        }
        println!("");
    }
}
