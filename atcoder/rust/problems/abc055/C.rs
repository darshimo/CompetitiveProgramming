fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read::<String>()
        .split_whitespace()
        .map(|e| e.parse().ok().unwrap())
        .collect()
}

fn main() {
    let v: Vec<u64> = read_vec();
    let n = v[0];
    let m = v[1];

    let ret: u64;
    if 2 * n > m {
        ret = m / 2;
    } else {
        ret = n + (m - 2 * n) / 4;
    }
    println!("{}", ret);
}
