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
    let w = v[0];
    let a = v[1];
    let b = v[2];

    if b > a + w {
        println!("{}", b - a - w);
    } else if a > b + w {
        println!("{}", a - b - w);
    } else {
        println!("0");
    }
}
