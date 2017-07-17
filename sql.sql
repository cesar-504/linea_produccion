
-- ---
-- Table 'Station'
-- 
-- ---

DROP TABLE IF EXISTS Station;
		
CREATE TABLE Station (
  id INTEGER NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (id)
);

-- ---
-- Table 'Product'
-- 
-- ---

DROP TABLE IF EXISTS Product;
		
CREATE TABLE Product (
  id INTEGER NULL AUTO_INCREMENT DEFAULT NULL,
  PRIMARY KEY (id)
);

-- ---
-- Table 'StationProductLog'
-- 
-- ---

DROP TABLE IF EXISTS StationProductLog;
		
CREATE TABLE StationProductLog (
  id INTEGER NOT NULL AUTO_INCREMENT,
  id_Station INTEGER NOT NULL,
  id_Product INTEGER NOT NULL,
  timeLog DATETIME NOT NULL DEFAULT 'now',
  id_LogAction INTEGER NOT NULL,
  PRIMARY KEY (id)
);

-- ---
-- Table 'LogAction'
-- 
-- ---

DROP TABLE IF EXISTS LogAction;
		
CREATE TABLE LogAction (
  id INTEGER NOT NULL AUTO_INCREMENT,
  name INTEGER NOT NULL,
  PRIMARY KEY (id)
);

-- ---
-- Foreign Keys 
-- ---

ALTER TABLE StationProductLog ADD FOREIGN KEY (id_Station) REFERENCES Station (id);
ALTER TABLE StationProductLog ADD FOREIGN KEY (id_Product) REFERENCES Product (id);
ALTER TABLE StationProductLog ADD FOREIGN KEY (id_LogAction) REFERENCES LogAction (id);


