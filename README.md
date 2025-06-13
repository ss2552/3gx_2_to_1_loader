# 共有メモリ

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

# サービス loader
○ lecacy loaderを有効化

○ sdカードをマウント

○ 3gxを開く

○ 3gxを読み込み書き込み

○ loaderを呼び出し実行

- 0x07FF7F00

bootrom 0x07FF8000 ~ 0x07FFF000

unknow memory field 0x0708DFFF

# ヒープ領域
3gx VA 0x06000000 | physical address ?0x0x060AC9F8
多分 3gx heap memory 0x0x060AC9F8


# あんま関係無い
top 0x1FFFE000
bottom 0x0x1FFFD000
