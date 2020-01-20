main = do
  [x1, x2, x3, x4] <- (map read . words) `fmap` getLine :: IO[Integer]
  let allSum = maximum [x1, x2, x3, x4]
  let [a, b, c] = filter (/=0) $ map ((-) allSum) [x1, x2, x3, x4]
  putStrLn $ (show a) ++ " " ++ (show b) ++ " " ++ (show c)


