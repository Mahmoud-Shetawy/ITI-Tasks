<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">

	<xsl:template match="/">
		<html>
			<head>
				<title></title>
			</head>
			<body>
				<table>
					<tr>
						<th>Title</th>
						<th>Artist</th>
						<th>Price</th>
					</tr>
					<xsl:for-each select="CATALOG/CD">
						<xsl:choose>
							<xsl:when test="PRICE > 10">
								<tr style="background-color: red; color:white;">
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
							</xsl:when>
							<xsl:otherwise>
								<tr style="background-color: green;color:white;">
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
							</xsl:otherwise>
					</xsl:choose>
					</xsl:for-each>
				</table>
			</body>
		</html>
	</xsl:template>


</xsl:stylesheet>
