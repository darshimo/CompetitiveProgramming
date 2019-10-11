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

use std::cmp::min;

fn main() {
    let n: usize = read();
    let a: Vec<i64> = read_vec();

    //start with plus
    let mut cnt1: i64 = 0;
    let mut sum = a[0];
    if sum <= 0 {
        cnt1 += 1 - sum;
        sum = 1;
    }
    for i in 1..n {
        if sum > 0 {
            if a[i] + sum < 0 {
                sum += a[i];
            } else {
                cnt1 += a[i] + sum + 1;
                sum = -1;
            }
        } else {
            if a[i] + sum > 0 {
                sum += a[i];
            } else {
                cnt1 += 1 - sum - a[i];
                sum = 1;
            }
        }
    }

    //start with minus
    let mut cnt2: i64 = 0;
    let mut sum = a[0];
    if sum >= 0 {
        cnt2 += 1 + sum;
        sum = -1;
    }
    for i in 1..n {
        if sum > 0 {
            if a[i] + sum < 0 {
                sum += a[i];
            } else {
                cnt2 += a[i] + sum + 1;
                sum = -1;
            }
        } else {
            if a[i] + sum > 0 {
                sum += a[i];
            } else {
                cnt2 += 1 - sum - a[i];
                sum = 1;
            }
        }
    }

    println!("{}", min(cnt1, cnt2));
}
