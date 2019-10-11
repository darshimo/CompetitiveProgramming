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

fn main() {
    let mut n: u32 = read();

    print!("{}:", n);

    let mut i: u32 = 2;
    while n > 1 {
        if i * i > n {
            print!(" {}", n);
            break;
        } else if n % i == 0 {
            n /= i;
            print!(" {}", i);
        } else {
            i += 1;
        }
    }
    println!("");
}
