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

fn gcd(a: u32, b: u32) -> u32 {
    assert!(a != 0 || b != 0);
    if a == 0 {
        b
    } else {
        gcd(b % a, a)
    }
}

fn lcm(a: u32, b: u32) -> u32 {
    a * b / gcd(a, b)
}

fn main() {
    let _n: u8 = read();
    let nums: Vec<u32> = read_vec();
    // &head に注意
    if let Some((&head, tail)) = nums.split_first() {
        // &b に注意
        println!("{}", tail.iter().fold(head, |a, &b| lcm(a, b)));
    }
}
