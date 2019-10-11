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

fn put(map: &Vec<Vec<bool>>, r: usize, c: usize) -> Vec<Vec<bool>> {
    let mut cln = map.clone();

    for i in 0..8 {
        cln[i][c] = true;
    }
    for j in 0..8 {
        cln[r][j] = true;
        if j <= r + c && r + c < j + 8 {
            cln[r + c - j][j] = true;
        }
        if c <= r + j && r + j < c + 8 {
            cln[r + j - c][j] = true;
        }
    }
    cln
}

fn solve(map: &Vec<Vec<bool>>, v: &mut Vec<Vec<usize>>, cnt: u32) -> bool {
    if cnt == 8 {
        return true;
    }
    for i in 0..8 {
        for j in 0..8 {
            if !map[i][j] {
                let cln = put(&map, i, j);
                let result = solve(&cln, v, cnt + 1);
                if result {
                    v.push(vec![i, j]);
                    return true;
                }
            }
        }
    }
    false
}

fn main() {
    let k: u32 = read();
    let mut v: Vec<Vec<usize>> = read_vec2(k);
    let mut map: Vec<Vec<bool>> = vec![vec![false; 8]; 8];
    for rc in &v {
        map = put(&map, rc[0], rc[1]);
    }
    solve(&map, &mut v, k);

    let mut ans: Vec<Vec<char>> = vec![vec!['.'; 8]; 8];
    for p in v {
        ans[p[0]][p[1]] = 'Q';
    }
    for a in ans {
        for b in a {
            print!("{}", b);
        }
        println!("");
    }
}
