# main - 0x07000100

○ plg:ldrの無効化

○ タイトルidの取得

○ sdカードをマウント

○ ファイルの位置を取得

○ 3gxを確認

○ 3gxを開く

○ 3gxヘッダーを読み込み

○ 3gxのサイズの確認

○ マジックの確認

○ もし
    マジックが0001ならbinをロード
  そうで無かったら
    0002を実行

# 共有メモリ ((max_size - loader_size - 1F) ~ sizeof 0x1F)

# サービス loader
○ lecacy loaderを有効化

○ sdカードをマウント

○ 3gxを開く

○ 3gxを読み込み書き込み

○ loaderを呼び出し実行

- 0x07FF7F00

bootrom 0x07FF8000 ~ 0x07FFF000

?0x0708DFFF

?heap?0x0x60AC9F8
