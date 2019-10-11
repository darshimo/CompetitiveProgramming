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
    let n: usize = read();
    let h: Vec<u32> = read_vec();
    let mut can: bool = true;
    let mut out: bool = false;
    for i in 0..(n - 1) {
        if h[i] > h[i + 1] + 1 {
            out = true;
            break;
        } else if h[i] == h[i + 1] + 1 {
            if can {
                can = false;
            } else {
                out = true;
                break;
            }
        } else if h[i] < h[i + 1] {
            can = true;
        }
    }
    if out {
        println!("No");
    } else {
        println!("Yes");
    }
}
