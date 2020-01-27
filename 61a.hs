main = do
  x1 <- getLine
  x2 <- getLine
  putStrLn $ zipWith comb x1 x2


comb :: Char -> Char -> Char
comb c1 c2
  | c1 == c2 = '0'
  | otherwise = '1'
  