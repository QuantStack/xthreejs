#ifndef XTHREE_CURVE_PATH_HPP
#define XTHREE_CURVE_PATH_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"
#include "../../base/xrender.hpp"

namespace xthree
{
    //
    // curve_path declaration
    //

    template<class D>
    class xcurve_path : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xcurve_path();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using curve_path = xw::xmaterialize<xcurve_path>;

    using curve_path_generator = xw::xgenerator<xcurve_path>;

    //
    // curve_path implementation
    //


    template <class D>
    inline void xcurve_path<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xcurve_path<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xcurve_path<D>::xcurve_path()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcurve_path<D>::set_defaults()
    {
        this->_model_name() = "CurvePathModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xcurve_path>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xcurve_path>;
        extern template xw::xmaterialize<xthree::xcurve_path>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xcurve_path>>;
        extern template class xw::xgenerator<xthree::xcurve_path>;
        extern template xw::xgenerator<xthree::xcurve_path>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xcurve_path>>;
    #endif
#endif

#endif