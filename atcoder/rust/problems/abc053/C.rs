fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    let x: u64 = s.trim().parse().ok().unwrap();

    let mut ans = (x / 11) * 2;
    ans += if x % 11 == 0 {
        0
    } else if x % 11 < 7 {
        1
    } else {
        2
    };
    println!("{}", ans);
}
