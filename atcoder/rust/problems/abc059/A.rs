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
    let s: Vec<String> = read_vec();
    println!(
        "{}{}{}",
        ((s[0].chars().next().unwrap() as u8) + ('A' as u8) - ('a' as u8)) as char,
        ((s[1].chars().next().unwrap() as u8) + ('A' as u8) - ('a' as u8)) as char,
        ((s[2].chars().next().unwrap() as u8) + ('A' as u8) - ('a' as u8)) as char
    );
}
