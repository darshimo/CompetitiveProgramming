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
    let v: Vec<i32> = read_vec();
    let a = v[0];
    let b = v[1];
    let c = v[2];

    if b - a == c - b {
        println!("YES");
    } else {
        println!("NO");
    }
}
