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

fn norm(v: Vec<f64>) -> f64 {
    (v[0] * v[0] + v[1] * v[1]).sqrt()
}

fn main() {
    let v: Vec<f64> = read::read_vec();
    let p1 = vec![v[0], v[1]];
    let p2 = vec![v[2], v[3]];
    let q: u32 = read::read();
    let ps: Vec<Vec<f64>> = read::read_vec2(q);

    for p in ps {}
}
