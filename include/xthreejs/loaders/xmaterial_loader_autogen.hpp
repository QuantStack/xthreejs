#ifndef XTHREE_MATERIAL_LOADER_HPP
#define XTHREE_MATERIAL_LOADER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // material_loader declaration
    //

    template<class D>
    class xmaterial_loader : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xmaterial_loader();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using material_loader = xw::xmaterialize<xmaterial_loader>;

    using material_loader_generator = xw::xgenerator<xmaterial_loader>;

    //
    // material_loader implementation
    //


    template <class D>
    inline void xmaterial_loader<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xmaterial_loader<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xmaterial_loader<D>::xmaterial_loader()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xmaterial_loader<D>::set_defaults()
    {
        this->_model_name() = "MaterialLoaderModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xmaterial_loader));
//}
#endif