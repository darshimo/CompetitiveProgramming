fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    let v: Vec<i32> = s
        .trim()
        .split_whitespace()
        .map(|e| e.parse().ok().unwrap())
        .collect();
    let n = v[0];
    let m = v[1];

    let mut a: Vec<Vec<char>> = Vec::new();
    for _i in 0..n {
        s = String::new();
        std::io::stdin().read_line(&mut s).ok();
        a.push(s.trim().chars().collect::<Vec<char>>());
    }
    let mut b: Vec<Vec<char>> = Vec::new();
    for _i in 0..m {
        s = String::new();
        std::io::stdin().read_line(&mut s).ok();
        b.push(s.trim().chars().collect::<Vec<char>>());
    }

    let mut c = false;
    'outer: for y in 0..n - m + 1 {
        for x in 0..n - m + 1 {
            c = diff(&a, &b, x, y, m);
            if c {
                break 'outer;
            }
        }
    }

    if c {
        println!("Yes");
    } else {
        println!("No");
    }
}

fn diff(a: &Vec<Vec<char>>, b: &Vec<Vec<char>>, x: i32, y: i32, m: i32) -> bool {
    for j in 0..m {
        for i in 0..m {
            if a[(x + i) as usize][(y + j) as usize] != b[i as usize][j as usize] {
                return false;
            }
        }
    }
    true
}
