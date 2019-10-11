fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

fn check(v: &Vec<i32>, n: i32, a0: i32, a1: i32) -> Option<Vec<i32>> {
    let mut a: Vec<i32> = vec![];
    a.push(a0);
    a.push(a1);
    for i in 0..n {
        let tmp1 = a[i as usize];
        let tmp2 = a[(i + 1) as usize];
        let tmp = tmp1 * tmp2 * v[((i + 1) % n) as usize];
        a.push(tmp);
    }

    if a0 == a[n as usize] && a1 == a[(n + 1) as usize] {
        Some(a.clone())
    } else {
        None
    }
}

fn main() {
    let n: i32 = read();
    let s: String = read();
    let v: Vec<i32> = s.chars().map(|e| if e == 'o' { 1 } else { -1 }).collect();

    if let Some(a) = check(&v, n, 1, 1) {
        for i in 0..n {
            if a[i as usize] == 1 {
                print!("S");
            } else {
                print!("W");
            }
        }
    } else if let Some(a) = check(&v, n, 1, -1) {
        for i in 0..n {
            if a[i as usize] == 1 {
                print!("S");
            } else {
                print!("W");
            }
        }
    } else if let Some(a) = check(&v, n, -1, 1) {
        for i in 0..n {
            if a[i as usize] == 1 {
                print!("S");
            } else {
                print!("W");
            }
        }
    } else if let Some(a) = check(&v, n, -1, -1) {
        for i in 0..n {
            if a[i as usize] == 1 {
                print!("S");
            } else {
                print!("W");
            }
        }
    } else {
        print!("-1");
    }
    println!("");
}
