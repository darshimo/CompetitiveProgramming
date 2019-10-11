fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    let v: Vec<i32> = s
        .trim()
        .split_whitespace()
        .map(|e| e.parse().ok().unwrap())
        .collect();
    let a = v[0];
    let b = v[1];
    if a == b {
        println!("Draw");
    } else if a == 1 {
        println!("Alice");
    } else if b == 1 {
        println!("Bob");
    } else if a > b {
        println!("Alice");
    } else {
        println!("Bob");
    }
}
