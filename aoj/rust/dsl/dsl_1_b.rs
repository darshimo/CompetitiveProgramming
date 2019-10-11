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

struct UnionFind {
    size: Vec<usize>,
    parent: Vec<Option<usize>>,
    diff: Vec<i32>,
}

impl UnionFind {
    fn new(n: usize) -> UnionFind {
        UnionFind {
            size: vec![1; n],
            parent: vec![None; n],
            diff: vec![0; n],
        }
    }

    fn get_parent_diff(&mut self, x: usize) -> (usize, i32) {
        match self.parent[x] {
            None => (x, 0),
            Some(y) => {
                let (p, d) = self.get_parent_diff(y);
                self.parent[x] = Some(p);
                self.diff[x] = d + self.diff[x];
                (p, self.diff[x])
            }
        }
    }

    fn relate(&mut self, x: usize, y: usize, z: i32) {
        let (xp, dx) = self.get_parent_diff(x);
        let (yp, dy) = self.get_parent_diff(y);

        if xp != yp {
            let sxp = self.size[xp];
            let syp = self.size[yp];
            if sxp < syp {
                self.parent[xp] = Some(yp);
                self.diff[xp] = z + dy - dx;
                self.size[yp] = sxp + syp;
            } else {
                self.parent[yp] = Some(xp);
                self.diff[yp] = dx - dy - z;
                self.size[xp] = sxp + syp;
            }
        }
    }

    fn diff(&mut self, x: usize, y: usize) -> Option<i32> {
        let (xp, dx) = self.get_parent_diff(x);
        let (yp, dy) = self.get_parent_diff(y);
        if xp != yp {
            None
        } else {
            Some(dx - dy)
        }
    }

    fn print(&self) {
        for i in 0..self.parent.len() {
            let op = &self.parent[i];
            match op {
                None => print!("root({}), ", self.size[i]),
                Some(p) => print!("{}({}), ", p, self.diff[i]),
            }
        }
    }
}

fn main() {
    let nq: Vec<usize> = read::read_vec();
    let n = nq[0];
    let q = nq[1];

    let coms: Vec<Vec<usize>> = read::read_vec2(q as u32);

    let mut uf = UnionFind::new(n);

    for cv in coms {
        if cv[0] == 0 {
            uf.relate(cv[1], cv[2], cv[3] as i32);

            uf.print();
            println!("");
        } else {
            if let Some(d) = uf.diff(cv[1], cv[2]) {
                println!("{}", d);
            } else {
                println!("?");
            }

            uf.print();
            println!("");
        }
    }
}
