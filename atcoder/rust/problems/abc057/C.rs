fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

fn cnt(mut u: u64) -> i32 {
    let mut a = 0;
    loop {
        a += 1;
        u /= 10;
        if u == 0 {
            break;
        }
    }
    a
}

fn solve(n: u64) -> u64 {
    let s = (n as f64).sqrt() as u64;
    let mut ret: u64 = s;

    for i in 0..s {
        let tmp = s - i;
        if tmp * (n / tmp) == n {
            ret = n / tmp;
            break;
        }
    }
    ret
}

fn main() {
    let n: u64 = read();

    println!("{}", cnt(solve(n)));
}
