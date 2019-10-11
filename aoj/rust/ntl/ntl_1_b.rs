pub fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

pub fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read::<String>()
        .split_whitespace()
        .map(|e| e.parse().ok().unwrap())
        .collect()
}

pub fn read_vec2<T: std::str::FromStr>(n: u32) -> Vec<Vec<T>> {
    (0..n).map(|_| read_vec()).collect()
}

pub fn read_col<T: std::str::FromStr>(n: u32) -> Vec<T> {
    (0..n).map(|_| read()).collect()
}

fn num2bit(mut n: u64) -> Vec<bool> {
    let mut ret = vec![];
    while n > 0 {
        ret.push((n % 2) == 1);
        n /= 2;
    }
    ret
}

fn solve(mut m: u64, bits: Vec<bool>) -> u64 {
    let mut ret: u64 = 1;
    for b in bits {
        if b {
            ret = (ret * m) % 1000000007;
        }
        m = (m * m) % 1000000007;
    }
    ret
}

fn main() {
    let v: Vec<u64> = read::read_vec();
    let m = v[0];
    let n = v[1];

    let bits = num2bit(n);

    println!("{}", solve(m, bits));
}
