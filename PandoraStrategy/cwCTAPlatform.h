#pragma once
#include "cwBasicKindleStrategy.h"
#include "cwBasicCTAStrategy.h"
#include "cwPandoraAgentManager.h"

#include "cwDualTrust.h"


class cwCTAPlatform :
    public cwBasicKindleStrategy
{
public:
	cwCTAPlatform();
	~cwCTAPlatform();


	enum cwStrategyEnum:int
	{
		cw_DualTrust_Strategy = 0
		, cwStrategyCount
	};


	struct StrategyContext
	{
		cwKindleSeriesPtr pKindleSeries;
	};

#ifdef _MSC_VER
#pragma region CommenDefine
#endif // _MSC_VER
	struct StrategyParameter
	{
		std::string	StrategyID;

		std::string StrategyName;

		bool		bIndex;
		int			iTimeScale;
		std::string InstrumentID;

		double		dMultiple;

		union
		{
			double			ParaList[50];
			struct
			{
				double		CTAPara1;
				double		CTAPara2;
				double		CTAPara3;
				double		CTAPara4;
				double		CTAPara5;
				double		CTAPara6;
				double		CTAPara7;
				double		CTAPara8;
				double		CTAPara9;
				double		CTAPara10;
				double		CTAPara11;
				double		CTAPara12;
				double		CTAPara13;
				double		CTAPara14;
				double		CTAPara15;
				double		CTAPara16;
				double		CTAPara17;
				double		CTAPara18;
				double		CTAPara19;
				double		CTAPara20;
				double		CTAPara21;
				double		CTAPara22;
				double		CTAPara23;
				double		CTAPara24;
				double		CTAPara25;
				double		CTAPara26;
				double		CTAPara27;
				double		CTAPara28;
				double		CTAPara29;
				double		CTAPara30;
				double		CTAPara31;
				double		CTAPara32;
				double		CTAPara33;
				double		CTAPara34;
				double		CTAPara35;
				double		CTAPara36;
				double		CTAPara37;
				double		CTAPara38;
				double		CTAPara39;
				double		CTAPara40;
				double		CTAPara41;
				double		CTAPara42;
				double		CTAPara43;
				double		CTAPara44;
				double		CTAPara45;
				double		CTAPara46;
				double		CTAPara47;
				double		CTAPara48;
				double		CTAPara49;
				double		CTAPara50;

			};
		};

		StrategyParameter()
			: bIndex(true)
			, iTimeScale(60)
			, dMultiple(1.0)
		{
			memset(ParaList, 0, sizeof(ParaList));
		}
	};
	typedef std::shared_ptr<StrategyParameter>			StrategyParaPtr;

	struct TradeParameter
	{
		// Instrument
		bool		Pause;						//��ͣ����Ըú�Լ�Ľ���

		std::string InstrumentID;				//���׺�Լ
		std::string	SignalInstrumentID;			//�ź����Ӧ�ĺ�Լ��
		double		Ratio;						//��Լ�µ�������
		bool		Mod;						//�µ���Լmod��1������ȡ����0������ȥ����

		cwOpenCloseMode InsOpenCloseMode;		//��ƽģʽ
		int			InsLargeOrderVolume;		//��������������Ϊ��
		int			InsLittleOrderVolume;		//С������С������ΪС��
		int			InsAskBidGap;				//�̿ڼ۲�
		int			InsAddTick;					//��������
		int			InsWaitInterval;			//�ҵ����̿ڼ۲� ��������ֵ

		TradeParameter()
			: Pause(false)
			, Ratio(0)
			, Mod(true)
			, InsOpenCloseMode(cwOpenCloseMode::CloseTodayThenYd)
			, InsLargeOrderVolume(100000)
			, InsLittleOrderVolume(100000)
			, InsAskBidGap(1)
			, InsAddTick(0)
			, InsWaitInterval(1)
		{

		}
		TradeParameter(TradeParameter& copy)
		{
			Pause = copy.Pause;

			InstrumentID = copy.InstrumentID;
			SignalInstrumentID = copy.SignalInstrumentID;
			Ratio = copy.Ratio;
			Mod = copy.Mod;

			InsOpenCloseMode = copy.InsOpenCloseMode;
			InsLargeOrderVolume = copy.InsLargeOrderVolume;
			InsLittleOrderVolume = copy.InsLittleOrderVolume;
			InsAskBidGap = copy.InsAskBidGap;
			InsAddTick = copy.InsAddTick;
			InsWaitInterval = copy.InsWaitInterval;
		}
	};
	typedef std::shared_ptr<TradeParameter>				TradeParaPtr;

	struct ManualIntervention
	{
		bool Manual;

		std::string StrategyID;

		std::string SignalID;
		double			ExpectedPosition;

		ManualIntervention()
			: Manual(false)
			, ExpectedPosition(0.0)
		{

		}
	};
	typedef std::shared_ptr<ManualIntervention>			ManualInterventionPtr;

	struct DirectionMask
	{
		std::string StrategyID;

		std::string SignalID;

		double		StrategyInsRatio;			//����ĳ������

		bool		NoLong;
		bool		NoShort;

		DirectionMask()
			: StrategyInsRatio(1.0)
			, NoLong(false)
			, NoShort(false)
		{

		}
	};
	typedef std::shared_ptr<DirectionMask>			DirectionMaskPtr;

	struct StrategyInstrumentUnion
	{
		std::string InstrumentID;		//InstrumentID
		std::string StrategyName;

		bool operator == (const StrategyInstrumentUnion& p) const
		{
			if (InstrumentID == p.InstrumentID
				&& StrategyName == p.StrategyName)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool operator < (const StrategyInstrumentUnion& p) const
		{
			if (StrategyName < p.StrategyName)
			{
				return true;
			}
			else
			{
				if (StrategyName == p.StrategyName
					&& InstrumentID < p.InstrumentID)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	};

#ifdef _MSC_VER
#pragma endregion
#endif

	struct CTAStrategyInfo
	{
		cwBasicCTAStrategy	*	_pStrategy;
		std::string				_StrategyID;
		StrategyParaPtr			_pParameter;
	};
	typedef std::shared_ptr<CTAStrategyInfo>					CTAStrategyInfoPtr;

	//struct 
public:
	//��ȡ���԰汾��
	virtual std::string  GetStrategyVersion();
	//��ʾ��������
	virtual std::string  GetStrategyName();

	//MarketData SPI
	///�������
	virtual void			PriceUpdate(cwMarketDataPtr pPriceData);
	//������һ����K�ߵ�ʱ�򣬻���øûص�
	virtual void			OnBar(cwMarketDataPtr pPriceData, int iTimeScale, cwBasicKindleStrategy::cwKindleSeriesPtr pKindleSeries);

	virtual void			OnReady();

	virtual void			OnStrategyTimer(int iTimerId, const char * szInstrumentID);


	virtual  void			InitialStrategy(const char* pConfigFilePath);
	bool					IsNearDeliverDateWarning(const char* szInstrumentID);
	int						GetTradingDayRemainWarning(const char* szInstrumentID);

	bool					ReadXmlConfigFile(const char * pConfigFilePath, bool bNeedDisPlay = true);



	bool					AddStrategyToPools(std::string strStrategyID, cwBasicCTAStrategy * pCTAStrategy, StrategyParaPtr pPara);
	void					SetKindle(std::string strStrategyID, bool bIndex, const char* szInstrumentID, int iTimeScale, int HisKindleCount);

	double					MergeStrategyPosition(std::string InstrumentID);
	
	cwInstrumentDataPtr		GetFirstInstrumentData(std::string ProductID);

	void					ShowSignalPosition();
	void					ShowManualInfor();


	///strategy parameter
	//�������д���
	std::string				m_strStrategyName;
	std::string				m_strCurrentUpdateTime;

	//�����Ƿ�����
	bool					m_bStrategyRun;
	bool					m_bShowPosition;

	double					m_dAccountRatio = 1.0;

	uint64_t				m_iKindleBeginTime = 0;


	//�˻�Ȩ����Ϣ
	double					m_dSignalPreBalance;				//�˻��ź�����ʱȨ�棨���գ�
	double                  m_dSignalBalance;					//�˻��ź�����Ȩ�棨���գ�

	double					m_dPreBalance;						//�˻�ʵ������ʱȨ�棨���գ�
	double					m_dBalance;							//�˻�ʵ������Ȩ�棨���գ�
protected:
	//���ò���
	//Key:StrategyID
	std::unordered_map<std::string, StrategyParaPtr>					m_StrategyParameterMap;
	//Key:TradeInstrumentID
	std::unordered_map<std::string, TradeParaPtr>						m_TradeParameterMap;

	//Key:StrategyID  value:ManualIntervention
	std::map<std::string, ManualInterventionPtr>						m_ManualinterventionMap;	
	//key:StrategyID value:DirectionMask
	std::map<std::string, DirectionMaskPtr>								m_DirectionMaskMap;			


	//Strategy pool���Գ�
	//key:SignalInstrument, key:TimeScale
	std::unordered_map<std::string, std::unordered_map<int, std::deque<CTAStrategyInfoPtr>>>		m_InsCTAStrategyList;
	//Key:StrategyID
	std::unordered_map<std::string, CTAStrategyInfoPtr>					m_NameCTAStrategy;

	//������� Portfolio
	//key:
	//std::unordered_map<std::string, std::deque<CTAStrategyInfoPtr>>		m_PortfolioStrategyList;


	//key:SignalInstrument, key:StrategyID
	std::map<std::string, std::map<std::string, double>> m_cwStrategyPositionMap;
	void		WriteSignalToFile();
	void		WriteNetAssetValueToFile();

	//Deal Trade Signal
	bool		GetParameter(const char * szInstrumentID, 
		TradeParameter& para, cwPandoraAgentManager::cwAgentDataPtr& pAgent);
	int			GetExpectedPosition(std::string InstrumentID, TradeParameter& para);


	//Agent
	cwPandoraAgentManager											m_PandoraAgentManager;		//�����˹����ߣ���ͨ��������������
	std::map<std::string, cwPandoraAgentManager::cwAgentDataPtr>	m_cwAgentDataMap;			//key Instrument value AgentData



	cwStrategyLog													m_StrategyLog;

	std::string														m_strWorkingPath;

	std::string						                                m_strConfigFileFullPath;
	bool					                                        m_bFirstGetConfig = true;
	time_t					                                        m_tLastestGetConfigTime;

	cwMUTEX					                                        m_ParameterMutex;
};
