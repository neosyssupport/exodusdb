DROP TABLE IF EXISTS DICT_VOC CASCADE;
CREATE TABLE IF NOT EXISTS DICT_VOC
(
 key text primary key,
 data text
);
INSERT INTO DICT_VOC (key,data) values (E'ARENT',E'RLISTNOT');
INSERT INTO DICT_VOC (key,data) values (E'ISNT',E'RLISTNOT');
INSERT INTO DICT_VOC (key,data) values (E'ITS',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'LOG_TIME',E'F0TimeS4MTSR5(MT)1');
INSERT INTO DICT_VOC (key,data) values (E'RECNUM',E'SRECNUMS*@reccount is the same thing@ANS=@REC.COUNTL100');
INSERT INTO DICT_VOC (key,data) values (E'NUM',E'SNUMS0@ANS=@IDHOLD=@IDCONVERT \'0123456789\' TO \'\' IN HOLDCONVERT HOLD TO \'\' IN @ANSR100');
INSERT INTO DICT_VOC (key,data) values (E'COLUMN_NAME',E'F0COLUMN_NAMES2L20');
INSERT INTO DICT_VOC (key,data) values (E'INPUT_TRUNCATION',E'F39INPUT_TRUNCATIONSL10VARCHAR1');
INSERT INTO DICT_VOC (key,data) values (E'REFERENCES',E'F30REFERENCESML10VARCHAR1');
INSERT INTO DICT_VOC (key,data) values (E'=',E'RLISTEQ');
INSERT INTO DICT_VOC (key,data) values (E'AND',E'RLISTAND');
INSERT INTO DICT_VOC (key,data) values (E'BY',E'RLISTBY');
INSERT INTO DICT_VOC (key,data) values (E'GRAND-TOTAL',E'RLISTGRAND-TOTAL');
INSERT INTO DICT_VOC (key,data) values (E'NOT',E'RLISTNOT');
INSERT INTO DICT_VOC (key,data) values (E'STARTS',E'RLIST]');
INSERT INTO DICT_VOC (key,data) values (E'THAN',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'LISTDICT_REP',E'GCOLHEAD "FIELD NAME" TYPE FMC PART MASTER_FLAG SM GENERIC_TYPE JUST LEN HEADING "\'FS22DS22\'PAGE\'PP\'"0');
INSERT INTO DICT_VOC (key,data) values (E'SIZE',E'SSIZES@ANS=LEN(@RECORD) + LEN(@ID) + 5R80');
INSERT INTO DICT_VOC (key,data) values (E'F5',E'F5FIELD 5MT10');
INSERT INTO DICT_VOC (key,data) values (E'<>',E'RLISTNOT');
INSERT INTO DICT_VOC (key,data) values (E'BECAUSE',E'RLISTWITH');
INSERT INTO DICT_VOC (key,data) values (E'TOTAL',E'RLISTTOTAL');
INSERT INTO DICT_VOC (key,data) values (E'=>',E'RLISTGE');
INSERT INTO DICT_VOC (key,data) values (E'LE',E'RLISTLE');
INSERT INTO DICT_VOC (key,data) values (E'SATURDAY',E'RLISTSAT');
INSERT INTO DICT_VOC (key,data) values (E'LATENT',E'RLISTNR');
INSERT INTO DICT_VOC (key,data) values (E'DIFFERENT',E'SDIFFERENTS$INSERT GBP,GENERAL.COMMON*COMMON /DIFFERENT/ LAST.RECCOUNT, COMPARE.FILE*IF COMPARE.FILE EQ \'\' THEN LAST.RECCOUNT = 9999**IF @RECCOUNT LT LAST.RECCOUNT THEN**  FN=\'\'**  CALL MSG(\'DIFFERENT FROM WHAT FILE\',\'RC\',FN,\'\')*fn=\'QFILE\'OPEN \'\',FN TO COMPARE.FILE ELSE STOP \'CANNOT OPEN \':FN*ENDLAST.RECCOUNT = @RECCOUNTREAD REC FROM COMPARE.FILE, @ID THEN  IF @RECORD EQ REC THEN @ANS = \'\' ELSE   IF @ID[1,1]=\'$\' THEN    REC.DATETIME=FIELD2(@RECORD,@FM,-1)    REC.DATETIME=TRIM(FIELD(REC.DATETIME,\' \',2,9)):\' \':FIELD(REC.DATETIME,\' \',1)    REC.DATETIME=ICONV(REC.DATETIME,\'DT\')    CMP.DATETIME=FIELD2(REC,@FM,-1)    CMP.DATETIME=TRIM(FIELD(CMP.DATETIME,\' \',2,9)):\' \':FIELD(CMP.DATETIME,\' \',1)    CMP.DATETIME=ICONV(CMP.DATETIME,\'DT\')    IF REC.DATETIME AND CMP.DATETIME ELSE GOTO CHANGED    IF REC.DATETIME EQ CMP.DATETIME THEN GOTO CHANGED    IF REC.DATETIME GT CMP.DATETIME THEN     @ANS=\'REPLACES\'    END ELSE     @ANS=\'REPLACED\'     END   END ELSECHANGED:    @ANS = \'CHANGED\'    END   ENDEND ELSE  @ANS = \'NEW REC\'ENDR10');
INSERT INTO DICT_VOC (key,data) values (E'F4',E'F4FIELD 4MT10');
INSERT INTO DICT_VOC (key,data) values (E'DT',E'SDTS0D2-@ANS=DATE()L10(D)0');
INSERT INTO DICT_VOC (key,data) values (E'DISPLAY2',E'SHEADINGS@ans=@record<3>convert @vm to \' \' in @ansL130');
INSERT INTO DICT_VOC (key,data) values (E'VERSION',E'SVERSIONSdeclare function field2if index(@dict,\'VOC\',1) then @ans=xlate(@record<3>,\'$\':@record<4>,\'VERSION\',\'X\')end else @ANS = FIELD2(@RECORD,@FM,-1) *IF @ANS[1,1] = \'V\' THEN *  @ANS=@ANS[2,99] *END ELSE *  @ANS = \'\' ENDL70');
INSERT INTO DICT_VOC (key,data) values (E'REFERENTIAL_INDEX',E'F23REFERENTIAL_INDEXSL10VARCHAR1');
INSERT INTO DICT_VOC (key,data) values (E'>',E'RLISTGT');
INSERT INTO DICT_VOC (key,data) values (E'GREATER',E'RLISTGT');
INSERT INTO DICT_VOC (key,data) values (E'BEFORE',E'RLISTLT');
INSERT INTO DICT_VOC (key,data) values (E'FOR',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'PG',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'LOG_SOURCE',E'F1SourceSL20');
INSERT INTO DICT_VOC (key,data) values (E'OBJECTCODETYPE',E'SOBJECTCODETYPES@ans=seq(@record<1>)L100');
INSERT INTO DICT_VOC (key,data) values (E'FOREIGN_TYPE',E'F15FOREIGN TYPESL101');
INSERT INTO DICT_VOC (key,data) values (E'JUST',E'F9JSTS0L3');
INSERT INTO DICT_VOC (key,data) values (E'FMC',E'F2FMCS0R3');
INSERT INTO DICT_VOC (key,data) values (E'FOREIGN_NAME',E'F16FOREIGN_NAMESL10VARCHAR1');
INSERT INTO DICT_VOC (key,data) values (E'LT',E'RLISTLT');
INSERT INTO DICT_VOC (key,data) values (E'INCLUDE',E'RLISTWITH');
INSERT INTO DICT_VOC (key,data) values (E'NO',E'RLISTNOT');
INSERT INTO DICT_VOC (key,data) values (E'OF',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'ID_R',E'F0Ref.S0R20');
INSERT INTO DICT_VOC (key,data) values (E'F14',E'F14FIELD 14ML10');
INSERT INTO DICT_VOC (key,data) values (E'LOWERCASE_INDEX',E'F26LOWERCASE_INDEXSR1BOOLEAN1');
INSERT INTO DICT_VOC (key,data) values (E'IN',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'LATER',E'RLISTGT');
INSERT INTO DICT_VOC (key,data) values (E'F0_3',E'F0Key Part 3S3L10');
INSERT INTO DICT_VOC (key,data) values (E'C_ARGS',E'SC ARGSS@ans=@record<2>if @ans[1,3] ne \'*c \' then @ans=\'\'T100');
INSERT INTO DICT_VOC (key,data) values (E'DESC',E'F14DESCS0T20');
INSERT INTO DICT_VOC (key,data) values (E'NLINES',E'SNLINESS0@ANS=COUNT(@RECORD,@FM)+1IF @RECORD EQ \'\' THEN @ANS=0R60');
INSERT INTO DICT_VOC (key,data) values (E'PART',E'F5PARTS0R2');
INSERT INTO DICT_VOC (key,data) values (E'ORDINAL',E'F2ORDINALSR50N_(0,32768)INTEGER');
INSERT INTO DICT_VOC (key,data) values (E'ARE',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'IS',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'STARTING',E'RLIST]');
INSERT INTO DICT_VOC (key,data) values (E'WHEN',E'RLISTWITH');
INSERT INTO DICT_VOC (key,data) values (E'WHENEVER',E'RLISTWITH');
INSERT INTO DICT_VOC (key,data) values (E'WITH',E'RLISTWITH');
INSERT INTO DICT_VOC (key,data) values (E'{',E'RLIST(');
INSERT INTO DICT_VOC (key,data) values (E'REDUCE',E'RLISTRP');
INSERT INTO DICT_VOC (key,data) values (E'DATETIME_CREATED',E'SDate TimeCreatedS[DATETIME]@ans={DATETIME_UPDATED}<1,1>R200');
INSERT INTO DICT_VOC (key,data) values (E'ALINES',E'SALINESS0@ANS=COUNT(@RECORD,\\\\0A\\\\)+1IF @RECORD EQ \'\' THEN @ANS=0R60');
INSERT INTO DICT_VOC (key,data) values (E'CONVERSION',E'F7CONVERSIONSL10VARCHAR');
INSERT INTO DICT_VOC (key,data) values (E'KEYPART',E'F5KEYPARTSR50N_(0,32768)INTEGER');
INSERT INTO DICT_VOC (key,data) values (E'UNIQUE_FLAG',E'F32UNIQUE_FLAGSR1BOOLEAN1');
INSERT INTO DICT_VOC (key,data) values (E'SHOWING',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'NOPAGE',E'RLIST(N)');
INSERT INTO DICT_VOC (key,data) values (E'MATCHING',E'RLISTMATCH');
INSERT INTO DICT_VOC (key,data) values (E'SOURCE',E'GWITH NOT @ID "$]" "*]"0');
INSERT INTO DICT_VOC (key,data) values (E'TIME',E'S3TIMEMTHS@ANS=FIELD(DIR(@ID),@FM,3)L90');
INSERT INTO DICT_VOC (key,data) values (E'ALL',E'SALLSANS=@ID:@FM:@RECORDreturn ansL200');
INSERT INTO DICT_VOC (key,data) values (E'SM',E'F4SMS0L4');
INSERT INTO DICT_VOC (key,data) values (E'NULL_FLAG',E'F31NULL_FLAGSR1BOOLEAN1');
INSERT INTO DICT_VOC (key,data) values (E'BETWEEN',E'RLISTBETWEEN');
INSERT INTO DICT_VOC (key,data) values (E'F8',E'F8FIELD 8ML10');
INSERT INTO DICT_VOC (key,data) values (E'JUSTIFICATION',E'F9JUSTIFICATIONSL10"L""R""C""T"CHAR(10)');
INSERT INTO DICT_VOC (key,data) values (E'NFIELDS00',E'SNFIELDS00S*remove comment blocksloop pos1=index(@record,\'/*\',1)while pos1 pos2=index(@record,\'*/\',1) if pos2 else pos2=len(@record)+1 @record[pos1,pos2-pos1+2]=\'\' repeat*call msg(\'x\')*remove comment linesnfields=count(@record,@fm)+1*dim x(nfields)*matparse @record into xfor i=1 to nfields *if trim(x(i))[1,1]=\'*\' then x(i)=\'\' if trim(@record<i>)[1,1]=\'*\' then @record<i>=\'\' next*@record=matunparse(x)*             call msg(\'y\')*remove blank linesconvert \\\\FE20\\\\ to \\\\20FE\\\\ in @recordnfields=count(trim(@record),\' \')+1@ans=nfieldsR100');
INSERT INTO DICT_VOC (key,data) values (E'LOG_SOURCE1',E'SSourceS@ans=field(@record<1>,\' \',1)L200');
INSERT INTO DICT_VOC (key,data) values (E'LINES',E'SLINESM0@ANS=@RECORDCONVERT @FM TO @VM IN @ANSL600');
INSERT INTO DICT_VOC (key,data) values (E'PATRN',E'F11PATRNS0T10');
INSERT INTO DICT_VOC (key,data) values (E'FOREIGN_ATTRIBUTES',E'F18FOREIGN_ATTRIBUTESSL10VARCHAR1');
INSERT INTO DICT_VOC (key,data) values (E'BY-DSND',E'RLISTBY-DSND');
INSERT INTO DICT_VOC (key,data) values (E'NEXT',E'RLISTNEXT');
INSERT INTO DICT_VOC (key,data) values (E'COLHEAD',E'RLISTCH');
INSERT INTO DICT_VOC (key,data) values (E'[]',E'RLIST[]');
INSERT INTO DICT_VOC (key,data) values (E'HAS',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'NFIELDS0',E'SNFIELDSSconvert \\\\FE20\\\\ to \\\\20FE\\\\ in @record@ans=count(trim(@record),\' \')+1L100');
INSERT INTO DICT_VOC (key,data) values (E'F0_1',E'F0Key Part 1S1L10');
INSERT INTO DICT_VOC (key,data) values (E'FORMULA',E'F8FORMULAS0T65');
INSERT INTO DICT_VOC (key,data) values (E'USER5',E'F45USER5SL101');
INSERT INTO DICT_VOC (key,data) values (E'DEFAULT',E'F29DEFAULTSL10"NULL""CURRENT""USER"\'"\'0X\'"\'VARCHAR1');
INSERT INTO DICT_VOC (key,data) values (E'PAGE',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'<=',E'RLISTLE');
INSERT INTO DICT_VOC (key,data) values (E'<',E'RLISTLT');
INSERT INTO DICT_VOC (key,data) values (E'MATCH',E'RLISTMATCH');
INSERT INTO DICT_VOC (key,data) values (E'OBJECT',E'GWITH  @ID "$]"0');
INSERT INTO DICT_VOC (key,data) values (E'PROGRAM_DATE',E'SPROGRAM DATES[DATE,4]ans={TIMEDATE}@ans=iconv(ans[11,99],\'D\')R120');
INSERT INTO DICT_VOC (key,data) values (E'EXPORTABLE',E'G@IDTYPEFMCDISPLAYSNJUSTLEN0');
INSERT INTO DICT_VOC (key,data) values (E'F3',E'F3FIELD 3ML10');
INSERT INTO DICT_VOC (key,data) values (E'NULL_TRUNCATION',E'F20NULL_TRUNCATIONSL10VARCHAR1');
INSERT INTO DICT_VOC (key,data) values (E'FOREIGN_MAP',E'F17FOREIGN_MAPSL10VARCHAR1');
INSERT INTO DICT_VOC (key,data) values (E'TEMP',E'STEMPS@ans=count(@record,\'xlate(\')R100');
INSERT INTO DICT_VOC (key,data) values (E'ANY',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'CONTAINING',E'RLIST[]');
INSERT INTO DICT_VOC (key,data) values (E'=<',E'RLISTLE');
INSERT INTO DICT_VOC (key,data) values (E'OR',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'KEY1',E'SKEY1S@ans=field(@id,\'*\',1)L100');
INSERT INTO DICT_VOC (key,data) values (E'SPACER',E'S---S@ans=\'\'L100');
INSERT INTO DICT_VOC (key,data) values (E'F6',E'F6FIELD 6M0L101');
INSERT INTO DICT_VOC (key,data) values (E'BY-EXP-DSND',E'RLISTBY-DSND');
INSERT INTO DICT_VOC (key,data) values (E'EACH',E'RLISTEVERY');
INSERT INTO DICT_VOC (key,data) values (E'MATCHES',E'RLISTMATCH');
INSERT INTO DICT_VOC (key,data) values (E'TUESDAY',E'RLISTTUE');
INSERT INTO DICT_VOC (key,data) values (E'EXCEPT',E'RLISTWITH NOT');
INSERT INTO DICT_VOC (key,data) values (E'USERNAME_CREATED',E'SUsernameCreatedS@ans={USERNAME_UPDATED}<1,1>L100');
INSERT INTO DICT_VOC (key,data) values (E'NUMID',E'F0NUMIDS0R10');
INSERT INTO DICT_VOC (key,data) values (E'ISCPP',E'SISCPPS@ans=@record<2>[1,3]=\'*c \'L100');
INSERT INTO DICT_VOC (key,data) values (E'USER4',E'F44USER4SL101');
INSERT INTO DICT_VOC (key,data) values (E'REFERRED',E'F24REFERREDSL10VARCHAR1');
INSERT INTO DICT_VOC (key,data) values (E'(',E'RLIST(');
INSERT INTO DICT_VOC (key,data) values (E'GE',E'RLISTGE');
INSERT INTO DICT_VOC (key,data) values (E'BY-EXP',E'RLISTBY');
INSERT INTO DICT_VOC (key,data) values (E'IT',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'LIMIT',E'RLISTLIMIT');
INSERT INTO DICT_VOC (key,data) values (E'NFIELDS',E'SNFIELDSS@ans=count(@record,@fm)+1R100');
INSERT INTO DICT_VOC (key,data) values (E'RECORD',E'SRECORDS@ANS=@RECORDT300');
INSERT INTO DICT_VOC (key,data) values (E'PROMPT',E'F12PROMPTS0L12');
INSERT INTO DICT_VOC (key,data) values (E'DISPLAY',E'F3HEADINGS0L13');
INSERT INTO DICT_VOC (key,data) values (E'MV',E'SMVMreturn @mvR30');
INSERT INTO DICT_VOC (key,data) values (E'VALIDATION',E'F11VALIDATIONML10VARCHAR');
INSERT INTO DICT_VOC (key,data) values (E'MASTER_DEFINITION',E'F28MASTER_DEFINITIONSR1BOOLEAN');
INSERT INTO DICT_VOC (key,data) values (E'MASTER_FLAG',E'F28MSTSBYes,L4');
INSERT INTO DICT_VOC (key,data) values (E'ONLY',E'RLISTONLY');
INSERT INTO DICT_VOC (key,data) values (E'#',E'RLISTNOT');
INSERT INTO DICT_VOC (key,data) values (E'INCLUDING',E'RLISTWITH');
INSERT INTO DICT_VOC (key,data) values (E'AVERAGE',E'RLISTAVERAGE');
INSERT INTO DICT_VOC (key,data) values (E'LOG_USERNAME',E'F0UsernameS2T201');
INSERT INTO DICT_VOC (key,data) values (E'LOG_MESSAGE2',E'SMessageSdeclare function trim2@ans=trim2(@record<2>,@vm)T300');
INSERT INTO DICT_VOC (key,data) values (E'LONG_FORMULA',E'F8FORMULAS0T60FORMULA');
INSERT INTO DICT_VOC (key,data) values (E'F7',E'F7FIELD 7MT10');
INSERT INTO DICT_VOC (key,data) values (E'USER3',E'F43USER3SL101');
INSERT INTO DICT_VOC (key,data) values (E'CROSSREFERENCED',E'F22CROSSREFERENCEDSR1BOOLEAN1');
INSERT INTO DICT_VOC (key,data) values (E'DET-SUPP',E'RLISTDS');
INSERT INTO DICT_VOC (key,data) values (E'LOG_MESSAGE',E'F2MessageST30');
INSERT INTO DICT_VOC (key,data) values (E'LINEMARKS',E'SLINEMARKSSif index(\'$*\',@id[1,1],1) then return \'\'end else if index(@record,\'linemark\',1) then tt=@record convert \' \' to @fm in tt return index(tt,@fm:\'linemark\',1)end else @ans=0 endreturn @ansL100');
INSERT INTO DICT_VOC (key,data) values (E'TYPE',E'F1TYPES0L4');
INSERT INTO DICT_VOC (key,data) values (E'TABLE_NAME',E'F0TABLE_NAMES1L20VARCHAR');
INSERT INTO DICT_VOC (key,data) values (E'DOESNT',E'RLISTNOT');
INSERT INTO DICT_VOC (key,data) values (E'FRIDAY',E'RLISTFRI');
INSERT INTO DICT_VOC (key,data) values (E'EXCLUDING',E'RLISTWITH NOT');
INSERT INTO DICT_VOC (key,data) values (E'TODAY',E'RLISTDAY');
INSERT INTO DICT_VOC (key,data) values (E']',E'RLIST]');
INSERT INTO DICT_VOC (key,data) values (E'LOG_DATE',E'F0DateS3[DATE,4]R12[DATE]1');
INSERT INTO DICT_VOC (key,data) values (E'F1',E'F1FIELD 1S00L101');
INSERT INTO DICT_VOC (key,data) values (E'USER2',E'F42USER2SL101');
INSERT INTO DICT_VOC (key,data) values (E'@ID',E'F0Ref.S0T20');
INSERT INTO DICT_VOC (key,data) values (E'MONDAY',E'RLISTMON');
INSERT INTO DICT_VOC (key,data) values (E'ENDING',E'RLIST[');
INSERT INTO DICT_VOC (key,data) values (E'THAT',E'RLISTWITH');
INSERT INTO DICT_VOC (key,data) values (E'USING',E'RLISTUSING');
INSERT INTO DICT_VOC (key,data) values (E'PROTECTED',E'F25PROTECTEDSL10BOOLEAN1');
INSERT INTO DICT_VOC (key,data) values (E'NORESOLVE',E'RLISTNR');
INSERT INTO DICT_VOC (key,data) values (E'COL-HDR-SUPP',E'RLISTCS');
INSERT INTO DICT_VOC (key,data) values (E'EXCLUDE',E'RLISTWITH NOT');
INSERT INTO DICT_VOC (key,data) values (E'EVERY',E'RLISTEVERY');
INSERT INTO DICT_VOC (key,data) values (E'OCONV',E'RLISTOC');
INSERT INTO DICT_VOC (key,data) values (E'VOC_ID',E'F0VOC.IDL10');
INSERT INTO DICT_VOC (key,data) values (E'ALLUPPERCASE',E'SALLSconvert @lower.case to @upper.case in @recordreturn @record*@ANS=@RECORD*convert @lower.case to @upper.case in @ansANS=@RECORDconvert @lower.case to @upper.case in ans*can cause out of memory*1. doesnt help*declare function memspace*mem=memspace(999999)*2. dont pass back in @ans variable seems to solve it!*transfer @ans to ans*if you return something then it uses it, otherwise it uses what is in @ansreturn @recordT300');
INSERT INTO DICT_VOC (key,data) values (E'ID',E'F0Ref.S0T20');
INSERT INTO DICT_VOC (key,data) values (E'F1_R',E'F1FIELD 1S0R10');
INSERT INTO DICT_VOC (key,data) values (E'COMPUTED_INDEX',E'F27COMPUTED_INDEXSL10VARCHAR1');
INSERT INTO DICT_VOC (key,data) values (E'INDEX_DEPENDANCIES',E'F21INDEX_DEPENDANCIESSL10VARCHAR1');
INSERT INTO DICT_VOC (key,data) values (E'DESCRIPTION',E'F14DESCRIPTIONMT20VARCHAR');
INSERT INTO DICT_VOC (key,data) values (E'ID-SUPP',E'RLISTIS');
INSERT INTO DICT_VOC (key,data) values (E'KEYLEN',E'SKEYLENS@ans=len(@id)R100');
INSERT INTO DICT_VOC (key,data) values (E'EQUAL',E'RLISTEQ');
INSERT INTO DICT_VOC (key,data) values (E'FOOTING',E'RLISTFOOTING');
INSERT INTO DICT_VOC (key,data) values (E'THURSDAY',E'RLISTTHU');
INSERT INTO DICT_VOC (key,data) values (E'LOG_WORKSTATION',E'F0WorkstationS1L201');
INSERT INTO DICT_VOC (key,data) values (E'ALPHA',E'SALPHAS0@ANS=@IDCONVERT \'0123456789\' TO \'\' IN @ANSL100');
INSERT INTO DICT_VOC (key,data) values (E'EXECUTIVE_NAME',E'SExecutiveS*ans={EXECUTIVE_CODE}*ans2=ans*convert @lower.case to @upper.case in ans2*@ans=xlate(\'USERS\',ans2,1,\'X\')*if @ans else @ans=ansdeclare function capitaliseans={EXECUTIVE_CODE}ans2=ansconvert @lower.case to @upper.case in ans2if ans2 ne ans then transfer ans to @ansend else *@ans=xlate(\'USERS\',\'%\':ans2:\'%\',1,\'X\') @ans=xlate(\'USERS\',ans2,1,\'X\') if @ans then  ans2=@ans  convert @lower.case to @upper.case in ans2  if ans2=@ans then   @ans=capitalise(@ans)   end end else  transfer ans to @ans  @ans=capitalise(@ans)  end endT200');
INSERT INTO DICT_VOC (key,data) values (E'DBL-SPC',E'RLISTDB');
INSERT INTO DICT_VOC (key,data) values (E'LESS',E'RLISTLT');
INSERT INTO DICT_VOC (key,data) values (E'HDR-SUPP',E'RLISTHS');
INSERT INTO DICT_VOC (key,data) values (E'CASERATIO',E'SCASERATIOSMD00Px=@recordconvert @lower.case to \'\' in xy=@recordconvert @upper.case to \'\' in yu=len(@record)-len(y)l=len(@record)-len(x)if u>l then @ans=u/(l+1) else @ans=-(l/(u+1))R100');
INSERT INTO DICT_VOC (key,data) values (E'[',E'RLIST[');
INSERT INTO DICT_VOC (key,data) values (E'TO',E'RLISTTO');
INSERT INTO DICT_VOC (key,data) values (E'CONTAINS',E'RLIST[]');
INSERT INTO DICT_VOC (key,data) values (E'LEN',E'F10LENS0R3LENGTH');
INSERT INTO DICT_VOC (key,data) values (E'F10',E'F10FIELD 10ML10');
INSERT INTO DICT_VOC (key,data) values (E'COUNT',E'SCountS@ANS=1R100');
INSERT INTO DICT_VOC (key,data) values (E'F2',E'F2FIELD 2MT10');
INSERT INTO DICT_VOC (key,data) values (E'OUTPUT_TRUNCATION',E'F40OUTPUT_TRUNCATIONSL10VARCHAR1');
INSERT INTO DICT_VOC (key,data) values (E'PHYSICAL_MAP_DOMAIN',E'F19PHYSICAL_MAP_DOMAINSL10VARCHAR1');
INSERT INTO DICT_VOC (key,data) values (E'REPEAT',E'F4REPEATSL1"S""M"CHAR(1)');
INSERT INTO DICT_VOC (key,data) values (E'EQ',E'RLISTEQ');
INSERT INTO DICT_VOC (key,data) values (E'LPTR',E'RLIST(P)');
INSERT INTO DICT_VOC (key,data) values (E'SUPP',E'RLISTHS');
INSERT INTO DICT_VOC (key,data) values (E'WHICH',E'RLISTWITH');
INSERT INTO DICT_VOC (key,data) values (E'WITHOUT',E'RLISTWITH NOT');
INSERT INTO DICT_VOC (key,data) values (E'IF',E'RLISTWITH');
INSERT INTO DICT_VOC (key,data) values (E'CH',E'RLISTCH');
INSERT INTO DICT_VOC (key,data) values (E'FIELD',E'SFIELDMIF @RECUR0 ELSE CALL MSG(\'WHICH FIELD NUMBER ?\',\'R\',@RECUR0,\'\') END@ANS=@RECORD<@RECUR0>L100');
INSERT INTO DICT_VOC (key,data) values (E'OVER',E'RLISTGT');
INSERT INTO DICT_VOC (key,data) values (E'>=',E'RLISTGE');
INSERT INTO DICT_VOC (key,data) values (E'JUSTLEN',E'RLISTJL');
INSERT INTO DICT_VOC (key,data) values (E'FILE',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'VERSION_DATE',E'SVERSION DATES[DATE,4]@ans=iconv(field(trim({VERSION}),\' \',2,3),\'D\')R100');
INSERT INTO DICT_VOC (key,data) values (E'EXECUTIVE_EMAIL',E'SExecutive EmailSexecutivecode={EXECUTIVE_CODE}convert @lower.case to @upper.case in executivecode*@ in executive name assume is an email emailif index(executivecode,\'@\',1) then @ans=executivecode convert \' ,\' to \';;\' in @ansend else *1) look for user code directly user=xlate(\'USERS\',executivecode,\'\',\'X\') *2) look for user name if user else user=xlate(\'USERS\',\'%\':executivecode:\'%\',\'\',\'X\') *3) try to use the first word of the executive code as the username *first name only if user else user=xlate(\'USERS\',field(executivecode,\' \',1),\'\',\'X\') if user<35> and date() ge user<35> then  *expired  @ans=\'\' end else  *not expired  @ans=user<7>  end *runtime users email if @ans else  @ans=xlate(\'USERS\',@username,7,\'X\')  end endL100');
INSERT INTO DICT_VOC (key,data) values (E'USER1',E'F41USER1SL101');
INSERT INTO DICT_VOC (key,data) values (E'TIMEDATE',E'STIMEDATES$INSERT GBP,GENERAL.COMMONANS = FIELD2(@RECORD,@FM,-1)IF ANS[1,1] = \'V\' THEN ANS = FIELD2(@RECORD,@FM,-2) ENDIF NOT(ANS[1,2] MATCHES \'2N\') THEN @ANS=\'\' ELSE @ANS = ANSL210');
INSERT INTO DICT_VOC (key,data) values (E'ANYDEBUG',E'SANYDEBUGSif index(\'*$\',@id[1,1],1) then return 0if @id=\'DEBUG\' then return 0if @id=\'MSG\' then return 0if @id=\'RTP25\' then return 0if @id=\'TEST\' then return 0if @id=\'TESTBASIC\' then return 0upper=@recordconvert @lower.case to @upper.case in upperif index(upper,\'DEBUG\',1) then return 1if @id=\'SENDMAIL\' then convert "\'EXODUS.ID\'" to \'\' in upperif index(upper,"\'EXODUS.ID\'",1) and @id<>\'INSTALLALLOWHOSTS\' then return 1return 0L100');
INSERT INTO DICT_VOC (key,data) values (E'INDEXED',E'F6INDEXEDSL1"1""0"BOOLEAN');
INSERT INTO DICT_VOC (key,data) values (E'GENERIC_TYPE',E'F12GENERIC_TYPESL10VARCHAR');
INSERT INTO DICT_VOC (key,data) values (E'HEADING',E'RLISTHEADING');
INSERT INTO DICT_VOC (key,data) values (E'F0_2',E'F0Key Part 2S2L10');
INSERT INTO DICT_VOC (key,data) values (E'SUNDAY',E'RLISTSUN');
INSERT INTO DICT_VOC (key,data) values (E'UNDER',E'RLISTLT');
INSERT INTO DICT_VOC (key,data) values (E'KEY3',E'SKEY3S@ans=field(@id,\'*\',3)L100');
INSERT INTO DICT_VOC (key,data) values (E'MASTER_FLAG',E'F28MASTER FLAGSBYes,L41');
INSERT INTO DICT_VOC (key,data) values (E'DATA',E'SDATAS0@ANS=@RECORDCONVERT \\\\FFFEFDFCFBFAF9F8\\\\ TO \'\' IN @ANSL100');
INSERT INTO DICT_VOC (key,data) values (E'KEYSIZE',E'SKey SizeS@ANS=LEN(@ID)R80');
INSERT INTO DICT_VOC (key,data) values (E'CLASS',E'F1CLASSSL1"F""S""G"CHAR(1)');
INSERT INTO DICT_VOC (key,data) values (E'A',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'NE',E'RLISTNOT');
INSERT INTO DICT_VOC (key,data) values (E'THE',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'DOES',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'DICT',E'RLISTDICT');
INSERT INTO DICT_VOC (key,data) values (E'BREAK-ON',E'RLISTBREAK-ON');
INSERT INTO DICT_VOC (key,data) values (E'SHOW',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'GTOT-SUPP',E'RLISTGTS');
INSERT INTO DICT_VOC (key,data) values (E'LOG@CRT',E'GLOG_DATE LOG_TIME LOG_USERNAME LOG_WORKSTATION LOG_SOURCE LOG_MESSAGE20');
INSERT INTO DICT_VOC (key,data) values (E'MAX_LENGTH',E'F33MAX_LENGTHSR50N_(1,65537)INTEGER1');
INSERT INTO DICT_VOC (key,data) values (E'DISPLAY_LENGTH',E'F10DISPLAY_LENGTHSL100N_(0,65537)INTEGER');
INSERT INTO DICT_VOC (key,data) values (E'F9',E'F9FIELD 9ML10');
INSERT INTO DICT_VOC (key,data) values (E'GENERIC_TYPE',E'F12GENERIC TYPESL15');
INSERT INTO DICT_VOC (key,data) values (E'CONV',E'F7CONVS0L9');
INSERT INTO DICT_VOC (key,data) values (E'FROM',E'RLISTFROM');
INSERT INTO DICT_VOC (key,data) values (E'}',E'RLIST)');
INSERT INTO DICT_VOC (key,data) values (E'YESTERDAY',E'RLISTYST');
INSERT INTO DICT_VOC (key,data) values (E'KEY4',E'SKEY4S@ans=field(@id,\'*\',4)L100');
INSERT INTO DICT_VOC (key,data) values (E'ITEMS',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'KEY2',E'SKEY2S@ans=field(@id,\'*\',2)L100');
INSERT INTO DICT_VOC (key,data) values (E'@CRT',E'GTYPE FMC PART DISPLAY2 SM CONV JUST LEN MASTER_FLAG0');
INSERT INTO DICT_VOC (key,data) values (E')',E'RLIST)');
INSERT INTO DICT_VOC (key,data) values (E'LIKE',E'RLISTEQ');
INSERT INTO DICT_VOC (key,data) values (E'GT',E'RLISTGT');
INSERT INTO DICT_VOC (key,data) values (E'FOREIGN_TYPE',E'F15FOREIGN TYPESL10');
INSERT INTO DICT_VOC (key,data) values (E'FINDALL',E'STestMif @record<1> then data=@record<8> convert @vm to @fm in dataend else data=@record endn=count(data,@fm)+1convert @lower.case to @upper.case in dataconvert \'"\' to "\'" in data@ans=\'\'for fn=1 to n tx=trim(data<fn>) if index(tx,\'xlate(\',1) and (index(tx,"\',\'C\')",1) or index(tx,"\',\'X\')",1)) then  *gosub change2  @ans<1,-1>=tx  end *if index(tx,\'MSG(\',1) and ( index(tx,",\'U",1) or index(tx,",\'D",1) or index(tx,",\'R",1) ) then * gosub change * @ans<1,-1>=tx * end *if index(tx,\'NOTE(\',1) and ( index(tx,",\'U",1) or index(tx,",\'D",1) or index(tx,",\'R",1) or index(tx,",\'T",1)) then * gosub change * @ans<1,-1>=tx * end next fnreturn @ans/*change: tx=data<fn> swap \'MSG(\' with \'msg2(\' in tx declare function decide2 if decide2(@id:@fm:tx:\'\',\'\',reply,2) else stop if reply=1 then  open \'TEMP\' to file else call fsmsg();stop  *writev tx on file,@id,fn  if @record<1>=\'S\' then   @record<8,fn>=tx  end else   @record<fn>=tx   end  write @record on file,@id  end return*/T600');
INSERT INTO DICT_VOC (key,data) values (E'CONV2UTF8',E'SCONV2UTF8Sorigrecord=@recordorigid=@idcall conv2utf8(msg,@recur0,\'\')@recur1+=1print @(0):@recur1:\'. \':@rec.count:@ans=msgif @ans else @ans=@record<>origrecord or @id<>origid end*restore otherwise select will not find it again@id=origidT100');
INSERT INTO DICT_VOC (key,data) values (E'AFTER',E'RLISTGT');
INSERT INTO DICT_VOC (key,data) values (E'AN',E'RLIST');
INSERT INTO DICT_VOC (key,data) values (E'USERNAME',E'SOperatorS@ANS=@USERNAMET200');
INSERT INTO DICT_VOC (key,data) values (E'LAST',E'RLISTLAST');
INSERT INTO DICT_VOC (key,data) values (E'TOMMORROW',E'RLISTTOM');
INSERT INTO DICT_VOC (key,data) values (E'UNLESS',E'RLISTWITH NOT');
INSERT INTO DICT_VOC (key,data) values (E'WEDNESDAY',E'RLISTWED');
