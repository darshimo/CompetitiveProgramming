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

fn parent(i: usize) -> usize {
    (i + 1) / 2 - 1
}

fn left(i: usize) -> usize {
    (i + 1) * 2 - 1
}

fn right(i: usize) -> usize {
    (i + 1) * 2
}

fn max_heapify(v: &mut Vec<i32>, i: usize) {
    let h = v.len();
    let l = left(i);
    let r = right(i);
    let mut largest = i;

    if l < h && v[l] > v[i] {
        largest = l;
    }
    if r < h && v[r] > v[largest] {
        largest = r;
    }

    if largest != i {
        let tmp = v[largest];
        v[largest] = v[i];
        v[i] = tmp;

        max_heapify(v, largest);
    }
}

fn build_max_heap(v: &mut Vec<i32>) {
    let h = v.len();
    for i in (0..h / 2).rev() {
        max_heapify(v, i);
    }
}

fn extract(v: &mut Vec<i32>) -> i32 {
    let ret = v[0];
    let last = v.pop().unwrap();

    if v.len() > 0 {
        v[0] = last;
        max_heapify(v, 0);
    }

    ret
}

fn insert(v: &mut Vec<i32>, x: i32) {
    v.push(x);
    let mut i: usize = v.len() - 1;
    while i > 0 {
        let p = parent(i);
        if v[i] < v[p] {
            break;
        }
        let tmp = v[i];
        v[i] = v[p];
        v[p] = tmp;
        i = p;
    }
}

fn main() {
    let mut v: Vec<i32> = Vec::new();

    loop {
        let s: String = read::read();
        if s == "end" {
            break;
        } else if s == "extract" {
            println!("{}", extract(&mut v));
        } else {
            let cv: Vec<String> = s
                .split_whitespace()
                .map(|e| e.parse().ok().unwrap())
                .collect();
            let i: i32 = cv[1].parse().ok().unwrap();
            insert(&mut v, i);
        }
    }
}
