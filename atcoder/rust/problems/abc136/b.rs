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

fn read_vec2<T: std::str::FromStr>(n: usize) -> Vec<Vec<T>> {
    (0..n).map(|_| read_vec()).collect()
}

fn read_col<T: std::str::FromStr>(n: usize) -> Vec<T> {
    (0..n).map(|_| read()).collect()
}

fn f(n: u32) -> u32 {
    let mut tmp = n;
    let mut cnt: u32 = 0;
    while tmp > 0 {
        cnt += 1;
        tmp = tmp / 10;
    }
    cnt
}

fn pow(a: u32, b: u32) -> u32 {
    let mut ans: u32 = 1;
    for _ in 0..b {
        ans *= a;
    }
    ans
}

fn main() {
    let n: u32 = read();
    let keta = f(n);
    let mut ans: u32 = 0;
    for i in 0..(keta / 2) {
        ans += 9 * pow(100, i);
    }
    if keta % 2 == 1 {
        ans += n + 1 - pow(10, keta - 1);
    }
    println!("{}", ans);
}
