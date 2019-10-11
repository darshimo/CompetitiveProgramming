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

fn abs(x: i32) -> i32 {
    if x > 0 {
        x
    } else {
        -x
    }
}

fn main() {
    let v: Vec<i32> = read_vec();
    let n = v[0];
    let m = v[1];

    let ab: Vec<Vec<i32>> = read_vec2(n as u32);
    let cd: Vec<Vec<i32>> = read_vec2(m as u32);

    let mut e: Vec<i32> = vec![];

    for i in 0..n {
        let mut d_min: i32 = abs(ab[i as usize][0] - cd[0][0]) + abs(ab[i as usize][1] - cd[0][1]);
        let mut p: i32 = 0;
        for j in 1..m {
            let tmp = abs(ab[i as usize][0] - cd[j as usize][0])
                + abs(ab[i as usize][1] - cd[j as usize][1]);
            if tmp < d_min {
                d_min = tmp;
                p = j;
            }
        }
        e.push(p);
    }

    for i in e {
        println!("{}", i + 1);
    }
}
