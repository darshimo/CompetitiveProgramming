fn main() {
    let x: i32 = read();
    if x < 1200 {
        println!("ABC");
    } else {
        println!("ARC");
    }
}

fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}
