// reference http://www.math.bas.bg/bantchev/place/rpn/rpn.rust.html
use std::io::prelude::*;

fn main() {
    let ins = std::io::stdin();
    for s in ins.lock().lines() {
        let mut stk: Vec<f64> = vec![];
        let mut err = false;
        for tk in s.unwrap().split_whitespace() {
            if let Ok(x) = tk.parse() {
                stk.push(x);
            } else {
                err = stk.len() < 2;
                if err {
                    break;
                }
                let (y, x) = (stk.pop().unwrap(), stk.pop().unwrap());
                match tk {
                    "+" => stk.push(x + y),
                    "-" => stk.push(x - y),
                    "*" => stk.push(x * y),
                    "/" => stk.push(x / y),
                    _ => {
                        err = true;
                        break;
                    }
                }
            }
        }
        if !err && stk.len() == 1 {
            println!("{}", stk[0]);
        } else if err || stk.len() > 1 {
            println!("error");
        }
    }
}
