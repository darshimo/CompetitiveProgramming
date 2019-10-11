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

fn cmb(n: u64, r: u64) -> u64 {
    if n == 0 {
        0
    } else if r == 1 {
        n
    } else {
        (n * cmb(n - 1, r - 1)) / r
    }
}

fn solve(v: &Vec<u64>, a: i32, b: i32, n: i32) -> (f64, u64) {
    let ave: f64;
    let c: u64;
    if v[0] == v[(a - 1) as usize] {
        ave = v[0] as f64;
        let mut cnt: i32 = 0;
        for i in 0..n {
            if v[i as usize] == v[0] {
                cnt += 1;
            }
        }
        let mut ret: u64 = 0;
        for i in a..(b + 1) {
            ret += cmb(cnt as u64, i as u64);
        }
        c = ret;
    } else {
        let mut sum: u64 = 0;
        let va = v[(a - 1) as usize];
        let mut cnt1: i32 = 0;
        for i in 0..a {
            sum += v[i as usize];
            if v[i as usize] == va {
                cnt1 += 1;
            }
        }
        ave = (sum as f64) / (a as f64);
        let mut cnt2 = cnt1;
        for i in a..n {
            if v[i as usize] == va {
                cnt2 += 1;
            }
        }
        c = cmb(cnt2 as u64, cnt1 as u64);
    }
    (ave, c)
}

fn sort(v: &mut Vec<u64>,n:i32) {
    for i in 0..n{
        let mut j = i-1;
        while j>=0 && v[j as usize]<v[(j+1) as usize]{
            let tmp = v[(j+1) as usize];
            v[(j+1) as usize] = v[j as usize];
            v[j as usize] =tmp;
            j-=1;
        }
    }
}

fn main() {
    let v: Vec<i32> = read_vec();
    let n = v[0];
    let a = v[1];
    let b = v[2];

    let mut v: Vec<u64> = read_vec();
    //v.sort_unstable_by(|a, b| b.cmp(a));
    sort(&mut v,n);
    let (ave, cmb) = solve(&v, a, b, n);
    println!("{}", ave);
    println!("{}", cmb);
}
