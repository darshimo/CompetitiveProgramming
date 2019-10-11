fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();

    let mut ia = 0;
    for c in s.chars() {
        if c == 'A' {
            break;
        }
        ia += 1;
    }

    let mut iz = 0;
    let mut tmp = 0;
    for c in s.chars() {
        if c == 'Z' {
            iz = tmp;
        }
        tmp += 1;
    }

    println!("{}", iz - ia + 1);
}
