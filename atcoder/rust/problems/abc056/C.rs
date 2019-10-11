fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

fn solve(x: i32) -> i32 {
    let mut i: i32 = 1;
    while i * (i - 1) / 2 < x {
        i += 1;
    }
    i-1
}

fn main() {
    let x: i32 = read();

    println!("{}", solve(x));
}
