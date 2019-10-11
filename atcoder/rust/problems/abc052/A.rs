fn main() {
    let v: Vec<i32> = read_vec();
    println!(
        "{}",
        std::cmp::max(
            v.get(0).unwrap() * v.get(1).unwrap(),
            v.get(2).unwrap() * v.get(3).unwrap()
        )
    );
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim()
        .split_whitespace()
        .map(|e| e.parse().ok().unwrap())
        .collect()
}
