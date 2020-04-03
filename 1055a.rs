#![allow(unused_variables)]
#![allow(unused_must_use)]
use std::io::{self, prelude::*};

use std::collections::HashMap;
use std::collections::HashSet;


fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
    let n: i32 = input.token();
    let s: i32 = input.token();

    let mut adj_list: HashMap<i32, Vec<i32>> = HashMap::new();

    for i in 1..(n+1) {
      adj_list.insert(i,Vec::new());
    }

    let mut prev = -1;
    for i in 1..(n+1) {
      let flag: i32 = input.token();
      if flag == 1 && prev != -1 {
        adj_list.get_mut(&prev).unwrap().push(i);
        prev = i;  
      } else if flag == 1 {
        prev = i;  
      }
      
    }

    prev = -1;
    for i in 1..(n+1) {
      let flag: i32 = input.token();
      if flag == 1 && prev != -1 {
        adj_list.get_mut(&i).unwrap().push(prev);
        prev = i;  
      } else if flag == 1 {
        prev = i;
      }
    }

    //write!(w, "{:?}\n", adj_list);

    let mut stack: Vec<i32> = Vec::new();
    let mut visited: HashSet<i32> = HashSet::new();

    stack.push(1);
    while stack.len() != 0 {
      let cur = stack.pop().unwrap();
      visited.insert(cur);
      for &i in  adj_list.get(&cur).unwrap() {
        if i == s {
          write!(w, "YES");
          return
        }
        if !visited.contains(&i) {
          stack.push(i)
        }
      }
    }

    write!(w, "NO");
}
 

fn main() {
  let stdin = io::stdin();
  let stdout = io::stdout();
  let input = FastInput::from(stdin.lock());
  let output = io::BufWriter::new(stdout.lock());
  solve(input, output)
}

trait TokenStream<T> {
    fn token(&mut self) -> T;
}
 
struct FastInput<R> {
    stdin: R,
    pos: usize,
}
 
impl<R: BufRead> From<R> for FastInput<R> {
    fn from(r: R) -> Self {
        FastInput { stdin: r, pos: 0 }
    }
}
 
impl<R: BufRead> TokenStream<u8> for FastInput<R> {
    fn token(&mut self) -> u8 {
        loop {
            if let Ok(buf) = self.stdin.fill_buf() {
                while self.pos < buf.len() {
                    self.pos += 1;
                    if buf[self.pos - 1] > 32 {
                        return buf[self.pos - 1];
                    }
                }
                if self.pos == 0 {
                    return 0;
                }
            } else {
                return 0;
            }
            self.stdin.consume(self.pos);
            self.pos = 0;
        }
    }
}
 
impl<R: BufRead> TokenStream<Vec<u8>> for FastInput<R> {
    fn token(&mut self) -> Vec<u8> {
        let mut ans = Vec::new();
        let mut parse_token = false;
        loop {
            if let Ok(buf) = self.stdin.fill_buf() {
                if !parse_token {
                    while self.pos < buf.len() && buf[self.pos] <= 32 {
                        self.pos += 1;
                    }
                }
                while self.pos < buf.len() && buf[self.pos] > 32 {
                    parse_token = true;
                    ans.push(buf[self.pos]);
                    self.pos += 1;
                }
                if self.pos != buf.len() || self.pos == 0 {
                    return ans;
                }
            }
            self.stdin.consume(self.pos);
            self.pos = 0;
        }
    }
}
 
macro_rules! impl_token_stream {
    ($($t:ident),+) => {$(
        impl<R: BufRead> TokenStream<$t> for FastInput<R> {
           fn token(&mut self) -> $t {
                let mut ans = 0;
                let mut parse_token = false;
                loop {
                    if let Ok(buf) = self.stdin.fill_buf() {
                        if !parse_token {
                            while self.pos < buf.len() && buf[self.pos] <= 32 {
                                self.pos += 1;
                            }
                        }
                        while self.pos < buf.len() && buf[self.pos] > 32 {
                            parse_token = true;
                            ans = ans * 10 + (buf[self.pos] - b'0') as $t;
                            self.pos += 1;
                        }
                        if self.pos != buf.len() || self.pos == 0 {
                            return ans;
                        }
                    }
                    self.stdin.consume(self.pos);
                    self.pos = 0;
                }
           }
        }
    )+}
}


impl_token_stream!(i32);