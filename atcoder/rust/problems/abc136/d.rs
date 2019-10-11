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

fn read_vec2<T: std::str::FromStr>(n: usize) -> Vec<Vec<T>> {
    (0..n).map(|_| read_vec()).collect()
}

fn read_col<T: std::str::FromStr>(n: usize) -> Vec<T> {
    (0..n).map(|_| read()).collect()
}

fn f(n: u32) -> u32 {
    let mut tmp = n;
    let mut cnt: u32 = 0;
    while tmp > 0 {
        cnt += 1;
        tmp = tmp / 10;
    }
    cnt
}

fn pow(a: u32, b: u32) -> u32 {
    let mut ans: u32 = 1;
    for _ in 0..b {
        ans *= a;
    }
    ans
}

fn main() {
    let s: String = read();
    let v: Vec<char> = s.chars().collect();
    let l = v.len();
    let mut ans: Vec<u32> = vec![0; l];

    let mut distance_left_R: Vec<usize> = vec![0; l];
    let mut rightest_r: usize = 0;
    for i in 0..l {
        if v[i] == 'R' {
            rightest_r = i;
            distance_left_R[i] = i;
        } else {
            distance_left_R[i] = rightest_r;
        }
    }

    let mut hoge: Vec<usize> = (0..l).collect();
    hoge.reverse();
    let it = hoge.iter();

    let mut distance_right_L: Vec<usize> = vec![0; l];
    let mut leftest_l: usize = 0;
    for &i in it {
        if v[i] == 'L' {
            leftest_l = i;
            distance_right_L[i] = i;
        } else {
            distance_right_L[i] = leftest_l;
        }
    }

    for i in 0..l {
        if v[i] == 'L' {
            let j = distance_left_R[i];
            if (i - j) % 2 == 0 {
                ans[j] += 1;
            } else {
                ans[j + 1] += 1;
            }
        } else {
            let j = distance_right_L[i];
            if (j - i) % 2 == 0 {
                ans[j] += 1;
            } else {
                ans[j - 1] += 1;
            }
        }
    }

    for i in 0..l {
        print!("{}", ans[i]);
        if i < l - 1 {
            print!(" ");
        } else {
            println!("");
        }
    }
}
