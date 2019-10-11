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

    let mut neighbor: Vec<Vec<i32>> = vec![Vec::new(); 8];

    for _i in 0..m {
        s = String::new();
        std::io::stdin().read_line(&mut s).ok();
        let v: Vec<i32> = s
            .trim()
            .split_whitespace()
            .map(|e| e.parse().ok().unwrap())
            .collect();
        let a = v[0] - 1;
        let b = v[1] - 1;

        neighbor[a as usize].push(b);
        neighbor[b as usize].push(a);
    }

    let mut check = vec![false; n as usize];

    println!("{}", cnt(0, &neighbor, &mut check));
}

fn cnt(v: i32, neighbor: &Vec<Vec<i32>>, check: &mut Vec<bool>) -> i32 {
    check[v as usize] = true;

    let mut ret = 0;

    let mut stuck = true;
    for u in neighbor[v as usize].iter() {
        if !check[*u as usize] {
            stuck = false;
            ret += cnt(*u, neighbor, check);
        }
    }

    if stuck {
        ret = 1;
        for b in check.iter() {
            if !b {
                ret = 0;
            }
        }
    }

    check[v as usize] = false;

    ret
}
