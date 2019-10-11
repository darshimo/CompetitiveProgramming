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

fn main() {
    let n:usize = read();
    let a:Vec<u64> = read_vec();

    let mut ans:u64 = 0;
    for i in 0..((n/2)+1){
        ans += a[i*2];
    }
    for i in 0..(n/2){
        ans -= a[i*2+1];
    }
    print!("{}", ans);
    for i in 0..(n-1){
        ans = 2*a[i] - ans;
        print!(" {}", ans);
    }
    println!("");
}
