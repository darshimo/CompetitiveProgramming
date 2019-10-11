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
    (i + 1) / 2
}

fn left(i: usize) -> usize {
    (i + 1) * 2 - 1
}

fn right(i: usize) -> usize {
    (i + 1) * 2
}

fn main() {
    let h: usize = read::read();
    let v: Vec<i32> = read::read_vec();

    for i in 0..h {
        print!("node {}: key = {}, ", i + 1, v[i]);
        let p = parent(i);
        if p > 0 {
            print!("parent key = {}, ", v[p - 1]);
        }
        let l = left(i);
        let r = right(i);
        if l < h {
            print!("left key = {}, ", v[l]);
        }
        if r < h {
            print!("right key = {}, ", v[r]);
        }
        println!("");
    }
}
