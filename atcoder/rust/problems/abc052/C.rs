fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).expect("error");
    let n: i64 = s.trim().parse().unwrap();
    let mut a = [1; 1000];
    let mut m;

    for j in 2..(n + 1) {
        m = j;
        for i in 2..(j + 1) {
            while m % i == 0 {
                m /= i;
                a[(i - 1) as usize] += 1;
            }
            if n == 1 {
                break;
            }
            //println!("{}", i);
        }
    }

    //println!("{}", ans);
    let mut ans: i64 = 1;
    for i in 0..n {
        ans *= a[i as usize] % 1000000007;
        ans %= 1000000007;
    }
    println!("{}", ans);
}
