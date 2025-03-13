<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"> 
    <xsl:template match="/">
        <html>
            <body>
                <h1>Список продуктов</h1>
                <table border="1" style="text-align:center;">
                    <tr bgcolor="#FF1493">
                        <th>ID</th>
                        <th>Название</th>
                        <th>Цена</th>
                        <th>Описание</th>
                        <th>Категория</th>
                    </tr>
                    <xsl:for-each select="store/products/product">
                        <xsl:sort select="price" data-type="number" order="ascending"/>
                        <tr>
                            <td bgcolor="#FF69B4"><xsl:value-of select="id"/></td>
                            <td><xsl:value-of select="name"/></td>
                            <td><xsl:value-of select="price"/></td>
                            <td><xsl:value-of select="description"/></td>
                            <td><xsl:value-of select="category"/></td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>