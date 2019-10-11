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

fn main() {
    let v: Vec<i64> = read_vec();
    let n = v[0];
    let m = v[1];
    let x: Vec<i64> = read_vec();
    let y: Vec<i64> = read_vec();

    let mut tmp1: i64 = 0;
    for i in 1..n {
        tmp1 = (tmp1 + i*(n-i)*(x[i as usize] - x[(i-1) as usize]))%1000000007;
    }
    let mut tmp2: i64 = 0;
    for i in 1..m {
        tmp2 = (tmp2 + i*(m-i)*(y[i as usize] - y[(i-1) as usize]))%1000000007;
    }

    println!("{}", (tmp1*tmp2)%1000000007);
}
