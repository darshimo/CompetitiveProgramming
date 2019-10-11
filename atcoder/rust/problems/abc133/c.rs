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

fn read_vec2<T: std::str::FromStr>(n: u32) -> Vec<Vec<T>> {
    (0..n).map(|_| read_vec()).collect()
}

fn read_col<T: std::str::FromStr>(n: u32) -> Vec<T> {
    (0..n).map(|_| read()).collect()
}

use std::cmp::min;

fn main() {
    let v: Vec<u64> = read_vec();
    let l = v[0];
    let r = v[1];

    if r - l > 700 {
        println!("0");
    } else {
        let mut ans: u64 = 10000;
        for i in l..r {
            for j in (i + 1)..(r + 1) {
                ans = min(ans, (i * j) % 2019);
            }
        }
        println!("{}", ans);
    }
}
