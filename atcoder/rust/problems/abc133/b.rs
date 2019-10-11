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

fn check(x1: &Vec<f64>, x2: &Vec<f64>, d: usize) -> u32 {
    let mut sum: f64 = 0.0;
    for i in 0..d {
        sum += (x1[i] - x2[i]) * (x1[i] - x2[i]);
    }
    let dist = sum.sqrt() as i32;
    if ((dist * dist) as f64) == sum  {
        1
    } else {
        0
    }
}

fn main() {
    let v: Vec<usize> = read_vec();
    let n = v[0];
    let d = v[1];
    let x: Vec<Vec<f64>> = read_vec2(n as u32);

    let mut ans: u32 = 0;
    for i in 0..n {
        for j in (i + 1)..n {
            ans += check(&x[i], &x[j], d);
        }
    }

    println!("{}", ans);
}
