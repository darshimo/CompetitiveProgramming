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

fn main() {
    let n: i32 = read();
    let v: Vec<i32> = read_col(n as u32);

    let mut min = std::cmp::min(v[0], v[1]);
    let mut max = v[1] - v[0];
    let mut tmp: i32;

    for i in 2..n {
        tmp = v[i as usize] - min;
        max = std::cmp::max(tmp, max);
        min = std::cmp::min(v[i as usize], min);
    }

    println!("{}", max);
}
