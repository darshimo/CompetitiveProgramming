fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).expect("error");

    s = String::new();
    std::io::stdin().read_line(&mut s).expect("error");
    let s = s.trim();

    let mut x = 0;
    let mut max = 0;
    for c in s.chars() {
        if c == 'I' {
            x += 1;
            if x > max {
                max = x;
            }
        } else {
            x -= 1;
        }
    }
    println!("{}", max);
}
