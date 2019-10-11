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
}

impl UnionFind {
    fn new(n: usize) -> UnionFind {
        UnionFind {
            size: vec![1; n],
            parent: vec![None; n],
        }
    }

    fn get_parent(&mut self, x: usize) -> usize {
        match self.parent[x] {
            None => x,
            Some(y) => {
                let p = self.get_parent(y);
                self.parent[x] = Some(p);
                p
            }
        }
    }

    fn unite(&mut self, x: usize, y: usize) {
        let xp = self.get_parent(x);
        let yp = self.get_parent(y);

        if xp != yp {
            let sxp = self.size[xp];
            let syp = self.size[yp];
            if sxp < syp {
                self.parent[xp] = Some(yp);
                self.size[yp] = sxp + syp;
            } else {
                self.parent[yp] = Some(xp);
                self.size[xp] = sxp + syp;
            }
        }
    }

    fn same(&mut self, x: usize, y: usize) -> bool {
        self.get_parent(x) == self.get_parent(y)
    }

    fn print(&self) {
        for i in 0..self.parent.len() {
            let op = &self.parent[i];
            match op {
                None => print!("root({}), ", self.size[i]),
                Some(p) => print!("{}, ", p),
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
            uf.unite(cv[1], cv[2]);
        } else {
            if uf.same(cv[1], cv[2]) {
                println!("1");
            } else {
                println!("0");
            }
        }
    }
}
