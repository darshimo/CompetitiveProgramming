fn main() {
    let v: Vec<i64> = read_vec();
    let n = v[0];
    let a = v[1];
    let b = v[2];

    let x: Vec<i64> = read_vec();
    let mut ans: i64 = 0;

    for i in 1..n {
        let tmp = (x[i as usize] - x[(i - 1) as usize]) * a;
        if tmp > b {
            ans += b;
        } else {
            ans += tmp;
        }
    }

    println!("{}", ans);
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim()
        .split_whitespace()
        .map(|e| e.parse().ok().unwrap())
        .collect()
}
