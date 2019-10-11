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

use std::cmp::min;

fn main() {
    let v: Vec<u32> = read_vec();
    let shower = v[1];
    let t: Vec<u32> = read_vec();
    let l = t.len();

    let mut w: u32 = shower;

    for i in 0..l - 1 {
        w += min(shower, t[i + 1] - t[i]);
    }

    println!("{}", w);
}
