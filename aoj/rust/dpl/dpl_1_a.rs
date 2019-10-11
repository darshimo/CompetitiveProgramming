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

use std::cmp::min;

fn solve(dp: &mut Vec<Vec<u32>>, n: usize, m: usize, c: &Vec<u32>) {
    for i in 0..m {
        for j in 1..(n + 1) {
            let tmp1;
            if i == 0 {
                tmp1 = 200000000;
            } else {
                tmp1 = dp[i - 1][j];
            }
            let tmp2;
            let ct = c[i] as usize;
            if j < ct {
                tmp2 = 2000000000;
            } else {
                tmp2 = 1 + dp[i][j - ct];
            }
            dp[i].push(min(tmp1, tmp2));
        }
    }
}

fn main() {
    let v: Vec<usize> = read::read_vec();
    let n = v[0];
    let m = v[1] as usize;
    let c: Vec<u32> = read::read_vec();

    let mut dp: Vec<Vec<u32>> = vec![vec![0]; m];

    solve(&mut dp, n, m, &c);

    println!("{}", dp[m - 1][n]);
}
