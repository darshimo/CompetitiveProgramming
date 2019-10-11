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

fn cmb_sub(n:u64,r:u64)->u64{
    if r==0{
        1
    }else{
        ((n * cmb_sub(n-1, r-1)) / r)
    }
}

fn cmb(n:u64,r:u64)->u64{
    if r < n-r{
        cmb_sub(n, r) % 1000000007
    }else{
        cmb_sub(n, n-r)% 1000000007
    }
}

fn main() {
    let v:Vec<u64>=read_vec();
    let n = v[0];
    let k = v[1];

    for i in 1..k+1{
        if i>n-k+1{
            println!("0");
        }else{
            println!("{}", (cmb(k-1,i-1)*cmb(n-k+1,i))%1000000007);
        }
    }
}
