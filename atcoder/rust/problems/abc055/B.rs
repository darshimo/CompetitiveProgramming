fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

fn fanc(n: u64) -> u64 {
    if n == 0 {
        1
    } else {
        (n * fanc(n - 1)) % 1000000007
    }
}

fn main() {
    let n: u64 = read();

    println!("{}", fanc(n));
}
