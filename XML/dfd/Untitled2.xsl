<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">

	<xsl:template match="/">
		<html>
			<head>
				<title></title>
			</head>
			<body>
				<table>
					<tbody>
						<tr>
							<th>Title</th>
							<th>Artist</th>
							<th>Price</th>
						</tr>
						<xsl:for-each select="CATALOG/CD">
							<xsl:if test="PRICE > 10">
								<tr>
									<td>
										<xsl:value-of select="TITLE"/>
									</td>
									<td>
										<xsl:value-of select="ARTIST"/>
									</td>
									<td>
										<xsl:value-of select="PRICE"/>
									</td>
								</tr>
							</xsl:if>
						</xsl:for-each>
						
					</tbody>
				</table>
			</body>
		</html>
	</xsl:template>

</xsl:stylesheet>
