#南京的芯片生成Excel
import xlwt
# 创建一个workbook 设置编码
workbook = xlwt.Workbook(encoding='utf-8')
# 创建一个worksheet
worksheet = workbook.add_sheet('My Worksheet', cell_overwrite_ok=True)
def my_sub(x,y):
    return x-y


def get_map():
    map_file = open(r"map.txt", 'r')

    xy = []  # xy位置
    val = []
    rows = 0
    cols = 0
    # 读取txt
    i = 0
    for lines in map_file.readlines():
        if i == 0:
            rows = int(lines.split(" ")[0])
            cols = int(lines.split(" ")[1])
            i = 1
        else:
            tmp = [int(lines.split(" ")[0]), int(lines.split(" ")[1]), int(lines.split(" ")[2])]
            xy.append(tmp)



    # 创建一个样式对象，初始化样式 style
    style = xlwt.XFStyle()

    # 生成表头
    for i in range(rows):
        alignment = xlwt.Alignment()
        alignment.horz = 2  # 设置水平位置，1是左对齐，2是居中，3是右对齐
        style.alignment = alignment

        font = xlwt.Font()  # 为样式创建字体
        font.bold = True  # 加粗
        style.font = font  # 定义格式-字体

        worksheet.write(rows - i, 0, i + 1, style)
    for i in range(cols):
        # 背景颜色设置
        pattern = xlwt.Pattern()
        pattern.pattern = xlwt.Pattern.SOLID_PATTERN  # May be: NO_PATTERN, SOLID_PATTERN, or 0x00 through 0x12
        pattern.pattern_fore_colour = 7  # 给背景颜色赋值，2是红色，3是绿色
        style.pattern = pattern  # 把背景颜色加到表格样式里去

        # 单元格位置设置
        alignment = xlwt.Alignment()
        alignment.horz = 2  # 设置水平位置，1是左对齐，2是居中，3是右对齐
        style.alignment = alignment

        # 为样式创建字体格式
        font = xlwt.Font()
        font.bold = True  # 加粗
        style.font = font  # 定义格式-字体

        worksheet.write(0, i + 1, i + 1, style)

    for xy_tmp in xy:
        # print(val[0],val[1])
        if xy_tmp[2] == 0:  # NG
            # 背景颜色设置
            pattern = xlwt.Pattern()
            pattern.pattern = xlwt.Pattern.SOLID_PATTERN  # May be: NO_PATTERN, SOLID_PATTERN, or 0x00 through 0x12
            pattern.pattern_fore_colour = 2  # 给背景颜色赋值，2是红色，3是绿色
            style.pattern = pattern  # 把背景颜色加到表格样式里去

            # 单元格位置设置
            alignment = xlwt.Alignment()
            alignment.horz = 2  # 设置水平位置，0是左对齐，1是居中，2是右对齐
            style.alignment = alignment

            # 为样式创建字体格式
            font = xlwt.Font()
            font.bold = False  # 加粗
            style.font = font  # 定义格式-字体

            worksheet.write(rows - xy_tmp[0] + 1, xy_tmp[1], xy_tmp[2], style)  # 参数对应 行, 列, 值, 格式

        else:
            # 背景颜色设置
            pattern = xlwt.Pattern()
            pattern.pattern = xlwt.Pattern.SOLID_PATTERN  # May be: NO_PATTERN, SOLID_PATTERN, or 0x00 through 0x12
            pattern.pattern_fore_colour = 3  # 给背景颜色赋值，2是红色，3是绿色
            style.pattern = pattern  # 把背景颜色加到表格样式里去

            # 单元格位置设置
            alignment = xlwt.Alignment()
            alignment.horz = 2  # 设置水平位置，1是左对齐，2是居中，3是右对齐
            style.alignment = alignment

            # 为样式创建字体格式
            font = xlwt.Font()
            font.bold = False  # 加粗
            style.font = font  # 定义格式-字体

            worksheet.write(rows - xy_tmp[0] + 1, xy_tmp[1], xy_tmp[2], style)  # 参数对应 行, 列, 值, 格式

    # 保存
    workbook.save('map.xlsx')
