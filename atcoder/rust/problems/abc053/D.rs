use std::collections::HashSet;

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    let _n: i32 = s.trim().parse().ok().unwrap();
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    let a: Vec<i32> = s
        .trim()
        .split_whitespace()
        .map(|e| e.parse().ok().unwrap())
        .collect();
    let uniq: HashSet<i32> = a.into_iter().collect();
    let uniq: i32 = uniq.len() as i32;

    println!("{}", ((uniq + 1) / 2) * 2 - 1)
}
